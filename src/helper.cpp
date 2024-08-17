/**
 * @file helper.cpp
 * @author Debojit Kumar Das
 * @brief This file defines orderbook entry class
 * @version 0.1
 * @date 2023-11-25
 *
 * @copyright Copyright (c) 2023
 */

#include "helper.hpp"
#include "csv_reader.hpp"
#include <cstdlib>
#include <iostream>
#include <vector>

Helper::Helper() : orders{} { }

void Helper::Init(std::string file_path) {
    int input;

    LoadOrderBook(file_path);

    while (true) {
        PrintMenu();
        input = GetUserOption();
        ProcessUserOption(input);
    }
}

void Helper::LoadOrderBook(std::string& file_path) {
    orders = CSVReader::ReadCSV(file_path);
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
        << "===========================\n";
}
void Helper::PrintHelp() {
    std::cout << "Help - your aim is to make money. Analyse the market and make money.\n";
}
void Helper::PrintMarketStats() {
    std::cout << "Oderbook contains: " << orders.size() << " entries.\n";
    unsigned int bids = 0;
    unsigned int asks = 0;

    for (auto& ord : orders) {
        if (ord.CheckOrderType(ord) == OrderBookType::ASK)
            asks++;
        if (ord.CheckOrderType(ord) == OrderBookType::BID)
            bids++;
    }

    std::cout << "asks: " << asks << '\t' << "bids: " << bids << '\n';
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
