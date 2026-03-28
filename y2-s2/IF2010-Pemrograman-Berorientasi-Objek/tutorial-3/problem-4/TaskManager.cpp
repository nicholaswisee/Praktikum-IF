#include "TaskManager.hpp"
#include <iostream>

void TaskManager::add(const string &id, const string &title, int priority,
                      int duration) {
    tasks.push_back(Task(id, title, priority, duration));
}

void TaskManager::add(const Task &task) { tasks.push_back(task); }

void TaskManager::update(const string &id, const string &title, int priority,
                         int duration) {
    vector<Task>::iterator it =
        find_if(tasks.begin(), tasks.end(),
                [&id](const Task &task) { return task.getId() == id; });

    if (it != tasks.end()) {
        it->setTitle(title);
        it->setPriority(priority);
        it->setDuration(duration);
    }
}

bool TaskManager::remove(const string &id) {
    vector<Task>::iterator it =
        find_if(tasks.begin(), tasks.end(),
                [&id](const Task &task) { return task.getId() == id; });

    if (it == tasks.end()) {
        return false;
    }

    tasks.erase(it);
    return true;
}

const Task *TaskManager::find(const string &id) const {
    vector<Task>::const_iterator it =
        find_if(tasks.begin(), tasks.end(),
                [&id](const Task &task) { return task.getId() == id; });

    if (it == tasks.end()) {
        return nullptr;
    }

    return &(*it);
}

void TaskManager::sort() {
    std::sort(tasks.begin(), tasks.end(), [](const Task &a, const Task &b) {
        if (a.getPriority() != b.getPriority()) {
            return a.getPriority() > b.getPriority();
        }
        if (a.getDuration() != b.getDuration()) {
            return a.getDuration() < b.getDuration();
        }
        return a.getId() < b.getId();
    });
}

long long TaskManager::totalDuration(long long minPriority) const {
    return accumulate(tasks.begin(), tasks.end(), 0LL,
                      [minPriority](long long acc, const Task &task) {
                          if (task.getPriority() >= minPriority) {
                              return acc + task.getDuration();
                          }
                          return acc;
                      });
}

void TaskManager::print(const string &keyword) const {
    bool hasMatch = false;

    for (vector<Task>::const_iterator it = tasks.begin(); it != tasks.end();
         ++it) {
        if (it->getTitle().find(keyword) != string::npos) {
            hasMatch = true;
            cout << it->getId() << "|" << it->getTitle() << "|"
                 << it->getPriority() << "|" << it->getDuration() << "\n";
        }
    }

    if (!hasMatch) {
        cout << "EMPTY\n";
    }
}

void TaskManager::print() const {
    if (tasks.empty()) {
        cout << "EMPTY\n";
        return;
    }

    for (vector<Task>::const_iterator it = tasks.begin(); it != tasks.end();
         ++it) {
        cout << it->getId() << "|" << it->getTitle() << "|" << it->getPriority()
             << "|" << it->getDuration() << "\n";
    }
}
