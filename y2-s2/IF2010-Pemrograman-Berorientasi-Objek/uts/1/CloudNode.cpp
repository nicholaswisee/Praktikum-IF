#include "CloudNode.hpp"
#include "Formatter.hpp"

CloudNode::CloudNode(string server_name, int limit_gb)
    : server_name(server_name), used_gb(0), limit_gb(limit_gb) {
    Formatter::printCtor(this->server_name);
}

CloudNode::CloudNode(const CloudNode &other)
    : server_name(other.server_name + "_backup"), used_gb(0),
      limit_gb(other.limit_gb) {
    Formatter::printCCtor(server_name);
}

CloudNode &CloudNode::operator=(const CloudNode &other) {
    if (this != &other) {
        int copiedUsed = other.used_gb + 2;
        if (copiedUsed > limit_gb) {
            copiedUsed = limit_gb;
        }
        used_gb = copiedUsed;
    }
    Formatter::printAssign(server_name);
    return *this;
}

CloudNode::~CloudNode() { Formatter::printDtor(server_name); }

CloudNode CloudNode::operator+(int n) const {
    CloudNode result(*this);
    result.used_gb = used_gb;
    result.limit_gb += n;
    return result;
}

CloudNode CloudNode::operator-(int n) const {
    CloudNode result(*this);
    int decreased = used_gb - n;
    if (decreased < 0) {
        decreased = 0;
    }
    result.used_gb = decreased;
    return result;
}

void systemWipe(CloudNode &node) {
    node.used_gb = 0;
    node.limit_gb = 0;
}
