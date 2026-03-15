#include "DailyHabit.hpp"
#include "TodoItem.hpp"
#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    if (!(cin >> n))
        return 0;

    Activity *dashboard[105];
    int activityCount = 0;

    for (int i = 0; i < n; ++i) {
        string type, name;
        cin >> type >> name;

        if (type == "TODO") {
            dashboard[activityCount] = new TodoItem(name);
            activityCount++;
        } else if (type == "HABIT") {
            dashboard[activityCount] = new DailyHabit(name);
            activityCount++;
        }
    }

    int m;
    if (!(cin >> m))
        return 0;

    int totalScore = 0;

    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;

        if (x >= 1 && x <= activityCount) {
            int earned = dashboard[x - 1]->complete();
            totalScore += earned;
            cout << "Mendapat " << earned << " poin dari "
                 << dashboard[x - 1]->getName() << "\n";
        }
    }

    cout << "--- DASHBOARD AKHIR ---\n";
    for (int i = 0; i < activityCount; ++i) {
        cout << dashboard[i]->getStatus() << "\n";
    }
    cout << "Total Poin: " << totalScore << "\n";

    for (int i = 0; i < activityCount; ++i) {
        delete dashboard[i];
    }

    return 0;
}
