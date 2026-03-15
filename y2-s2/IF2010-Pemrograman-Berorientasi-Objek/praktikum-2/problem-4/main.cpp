#include "Paladin.hpp"

int main() {
    cout << "\n--- Paladin: Arthas ---\n";
    Paladin p1("C001", "Arthas", 100, 1, 25, 40, "Divine Light");
    p1.attack();
    p1.castSpell();
    p1.holyStrike();
    cout << "[STATUS] " << p1.showStatus() << "\n";

    cout << "\n--- Level Up ---\n";
    p1.levelUp();
    cout << "[STATUS] " << p1.showStatus() << "\n";

    cout << "\n--- Paladin: Uther ---\n";
    Paladin p2("C002", "Uther", 120, 5, 30, 50, "Holy Shield");
    p2.holyStrike();
    p2.levelUp();
    cout << "[STATUS] " << p2.showStatus() << "\n";

    cout << "\n--- Cleanup ---\n";

    return 0;
}
