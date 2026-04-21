#ifndef CLOUD_NODE_HPP
#define CLOUD_NODE_HPP

#include <string>

using std::string;

class CloudNode {
  private:
    string server_name;
    int used_gb;
    int limit_gb;

  public:
    CloudNode(string server_name, int limit_gb);
    CloudNode(const CloudNode &other);
    CloudNode &operator=(const CloudNode &other);
    ~CloudNode();

    CloudNode operator+(int n) const;
    CloudNode operator-(int n) const;

    friend void systemWipe(CloudNode &node);

    // Fungsi Getter, tidak perlu diubah
    int getUsedGB() const { return used_gb; }
    int getLimitGB() const { return limit_gb; }
};

#endif
