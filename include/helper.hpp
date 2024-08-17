/**
 * @file helper.hpp
 * @author Debojit Kumar Das
 * @brief This file defines orderbook entry class
 * @version 0.1
 * @date 2023-11-25
 *
 * @copyright Copyright (c) 2023
 */

#pragma once

#include "orderbookentry.hpp"
#include <string>
#include <vector>

class Helper {
public:
    Helper();
    /** Call this to start the simulation by providing the source of data */
    void Init(std::string file_path);

private:
    void LoadOrderBook(std::string&);
    void PrintMenu();
    void PrintHelp();
    void PrintMarketStats();
    void EnterOffer();
    void EnterBid();
    void PrintWallet();
    void GotoNextTimeframe();
    int GetUserOption();
    void ProcessUserOption(int user_option);

private:
    std::vector<OrderBookEntry> orders;
};
