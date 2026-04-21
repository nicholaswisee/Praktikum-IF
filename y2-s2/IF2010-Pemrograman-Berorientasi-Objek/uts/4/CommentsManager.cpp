#include "CommentsManager.hpp"

#include <algorithm>

void CommentsManager::kickSpammer(int threshold_score) {
    chat_log_.erase(
        std::remove_if(chat_log_.begin(), chat_log_.end(),
                       [this, threshold_score](const Comment &comment) {
                           const std::map<std::string, int>::const_iterator it =
                               reputation_.find(comment.getUsername());
                           const int score =
                               (it == reputation_.end()) ? 0 : it->second;
                           return score > threshold_score;
                       }),
        chat_log_.end());
}

void CommentsManager::printViolation() {
    bool has_violation = false;

    std::for_each(
        chat_log_.begin(), chat_log_.end(),
        [this, &has_violation](const Comment &comment) {
            std::for_each(
                comment.getWords().begin(), comment.getWords().end(),
                [this, &comment, &has_violation](const std::string &word) {
                    if (blacklist_.find(word) != blacklist_.end()) {
                        std::cout << "kata \"" << word << "\" oleh akun \""
                                  << comment.getUsername() << "\"" << std::endl;
                        has_violation = true;
                    }
                });
        });

    if (!has_violation) {
        std::cout << "TIDAK ADA PELANGGARAN" << std::endl;
    }
}

std::string
CommentsManager::quizWinner(const std::set<std::string> &passwords) {
    const std::vector<Comment>::const_iterator winner_it = std::find_if(
        chat_log_.begin(), chat_log_.end(),
        [&passwords](const Comment &comment) {
            return std::any_of(
                comment.getWords().begin(), comment.getWords().end(),
                [&passwords](const std::string &word) {
                    return passwords.find(word) != passwords.end();
                });
        });

    if (winner_it == chat_log_.end()) {
        return "BELUM ADA PEMENANG";
    }

    return winner_it->getUsername();
}

void CommentsManager::upVIPComment() {
    std::stable_partition(
        chat_log_.begin(), chat_log_.end(),
        [](const Comment &comment) { return comment.isVip(); });
}
