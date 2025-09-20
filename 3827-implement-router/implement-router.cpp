class Router {
private:
    int capacity;
    queue<long long> packets;
    unordered_map<long long, vector<int>> packetConfig;
    unordered_map<int, vector<int>> destinationTimestamp;

    long long getPacketConfigKey(int source, int destination, int timestamp){
        return ((long long)source<<40 | (long long)destination<<20) | timestamp;
    }

    int upperBound(vector<int> &list, int target){
        return (int)(upper_bound(list.begin(), list.end(), target) - list.begin());
    }

    int lowerBound(vector<int> &list, int target){
        return (int)(lower_bound(list.begin(), list.end(), target) - list.begin());
    }

public:
    Router(int memoryLimit) {
        this->capacity = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        long long packetConfigKey = getPacketConfigKey(source, destination, timestamp);
        if(packetConfig.find(packetConfigKey) != packetConfig.end()) return false;
        
        vector<int> packetConfigValue = {source, destination, timestamp};
        packets.push(packetConfigKey);
        packetConfig[packetConfigKey] = packetConfigValue;
        destinationTimestamp[destination].push_back(timestamp);

        if(packets.size() > capacity) {
            forwardPacket();
        }
        return true;
    }
    
    vector<int> forwardPacket() {
        if(packets.empty()) return {};
        long long packetConfigKey = packets.front(); packets.pop(); packetConfigKey;
        vector<int> packetData = packetConfig[packetConfigKey];
        packetConfig.erase(packetConfigKey);
        destinationTimestamp[packetData[1]].erase(destinationTimestamp[packetData[1]].begin());
        return packetData;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        auto itr = destinationTimestamp.find(destination);
        if(itr == destinationTimestamp.end() || itr->second.empty()) return 0;
        return upperBound(itr->second, endTime) - lowerBound(itr->second, startTime);
    }
};