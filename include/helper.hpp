/**
 * @file helper.hpp
 * @author Debojit Kumar Das
 * @brief This file defines the interface for helper class which provides various methods to ....
 * @version 0.1
 * @date 2023-11-25
 *
 * @copyright Copyright (c) 2023
 */

#ifndef HELPER_H
#define HELPER_H

#include "orderbook.hpp"
#include <string>

/**
 * @brief Defines a class that provides various methods ...
 */
class Helper {
public:
    /**
     * @brief
     */
    Helper();
    /** Call this to start the simulation by providing the source of data */
    void Init(std::string file_path);

private:
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
    // std::vector<OrderBookEntry> orders;
    std::string m_current_time;
    std::string m_filename = "data/20200317.csv";
    OrderBook m_orderbook{m_filename};
};

#endif // !HELPER_H
