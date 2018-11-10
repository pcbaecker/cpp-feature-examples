#include <iostream>
#include <list>
#include <ctime>

#include "Helper.hpp"

/**
 * @brief Reference class that doesnt have a special move constructor.
 */
class User {
public:
    User(uint32_t id, std::string name) : mId(id), mName(std::move(name)) {}

private:
    uint32_t mId;
    std::string mName;
};

/**
 * @brief Class that has a special move constructor.
 */
class UserWithMove {
public:
    UserWithMove(uint32_t id, std::string name) :mId(id), mName(std::move(name)) {}
    UserWithMove(UserWithMove&& u) noexcept : mId(u.mId), mName(std::move(u.mName)) {}

private:
    uint32_t mId;
    std::string mName;
};

std::list<User> createUsers() {
    std::list<User> userList;
    for (int i = 0; i < 100000; i++) {
        userList.emplace_back(i + 1, random_string(32));
    }
    return userList;
}

std::list<UserWithMove> createUsersWithMove() {
    std::list<UserWithMove> userList;
    for (int i = 0; i < 100000; i++) {
        userList.emplace_back(i + 1, random_string(32));
    }
    return userList;
}

int main() {
    clock_t begin = clock();
    const auto userList = createUsers();
    clock_t end = clock();
    clock_t diffOne = end - begin;
    std::cout << "CPU clocks without custom Move-Constructor: " << diffOne << std::endl;

    begin = clock();
    const auto userWithMoveList = createUsersWithMove();
    end = clock();
    clock_t diffTwo = end - begin;
    std::cout << "CPU clocks with a custom Move-Constructor:  " << diffTwo << std::endl;

    return 0;
}