/**
 * @file helper.cpp
 * @author Debojit Kumar Das
 * @brief This file implements the interface for helper class which provides various methods to ....
 * @version 0.1
 * @date 2023-11-25
 *
 * @copyright Copyright (c) 2023
 */

#include "helper.hpp"
#include "orderbookentry.hpp"
#include <cstdlib>
#include <iostream>
#include <vector>

Helper::Helper(){}

void Helper::Init([[maybe_unused]] std::string file_path) {
    int input;
    m_current_time = m_orderbook.GetEarliestTime();
    while (true) {
        PrintMenu();
        input = GetUserOption();
        ProcessUserOption(input);
    }
}

void Helper::PrintMenu() {
    std::cout << "===========================\n"
        << "1. Print help \n"
        << "2. Print exchange stats \n"
        << "3. Make an offer \n"
        << "4. Make a bid \n"
        << "5. Print Wallet \n"
        << "6. Continue \n"
        << "0. Exit \n"
        << "===========================\n"
        << "Current time is: " << m_current_time << '\n';
}
void Helper::PrintHelp() {
    std::cout << "Help - your aim is to make money. Analyse the market and make money.\n";
}
void Helper::PrintMarketStats() {
    for (auto const& p : m_orderbook.GetKnownProducts()) {
        std::cout << "Product: " << p << std::endl;

        std::vector<OrderBookEntry> entries = m_orderbook.GetOrders(OrderType::ASK, p, m_current_time);

        std::cout << "Asks for product: " << entries.size() << std::endl;
        std::cout << "Max ask: " << OrderBook::GetHighPrice(entries) << std::endl;
        std::cout << "Min ask: " << OrderBook::GetLowPrice(entries) << std::endl;
    }
    // std::cout << "Oderbook contains: " << orders.size() << " entries.\n";
    // unsigned int bids = 0;
    // unsigned int asks = 0;
    //
    // for (auto& ord : orders) {
    //     if (ord.CheckOrderType(ord) == OrderType::ASK)
    //         asks++;
    //     if (ord.CheckOrderType(ord) == OrderType::BID)
    //         bids++;
    // }
    //
    // std::cout << "asks: " << asks << '\t' << "bids: " << bids << '\n';
}

void Helper::EnterOffer() {
    std::cout << "Make an offer - enter the amount \n";
}

void Helper::EnterBid() {
    std::cout << "Make a bid - enter the amount \n";
}

void Helper::PrintWallet() {
    std::cout << "Your wallet is empty.\n";
}

void Helper::GotoNextTimeframe() {
    std::cout << "Go to next time frame.\n";
    m_current_time = m_orderbook.GetNextTime(m_current_time);
}

int Helper::GetUserOption() {
    int user_option;

    std::cout << "Type in 0-6: ";
    std::cin >> user_option;
    std::cout << "You chose: " << user_option << '\n';
    return user_option;
}

void Helper::ProcessUserOption(int user_option) {
    switch (user_option) {
        case 0:
            std::cout << "Exiting!!\n";
            exit(-1);
        case 1: // bad input
            PrintHelp();
            break;
        case 2: // bad input
            PrintMarketStats();
            break;
        case 3: // bad input
            EnterOffer();
            break;
        case 4: // bad input
            EnterBid();
            break;
        case 5: // bad input
            PrintWallet();
            break;
        case 6: // bad input
            GotoNextTimeframe();
            break;
        default: // bad input
            std::cout << "Invalid choice. Choose from 1-6.\n";
            break;
    }
}
