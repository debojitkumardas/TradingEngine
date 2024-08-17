/**
 * @file orderbookentry.hpp
 * @author Debojit Kumar Das
 * @brief This file defines orderbook entry class
 * @version 0.1
 * @date 2023-11-25
 *
 * @copyright Copyright (c) 2023
 */
#pragma once

#include <string>

/**
 * @brief Defines an enum class for asks and bids
 */
enum class OrderBookType {
    BID,    /**< offer to buy */
    ASK,    /**< offer to sell */
    NONE    /**< invalid option */
};

/**
 * @brief Defines a class that process orderbook entry.
 */
class OrderBookEntry {
public:
    /**
     * @brief Constructor for OrderBookEntry class to initialise data
     */
    OrderBookEntry(double price, double amount, std::string timestamp, std::string product, OrderBookType order_type);

    /**
     */
    static OrderBookType StringToOBT(std::string);

    /**
     */
    OrderBookType CheckOrderType(OrderBookEntry);

    /**
     */
    void GetValue() const;

private:
    double m_price;             /**< price of item */
    double m_amount;            /**< volume of transaction */
    std::string m_timestamp;    /**< time stamp */
    std::string m_product;      /**< product */
    OrderBookType m_order_type; /**< order type (bid or ask) */
};
