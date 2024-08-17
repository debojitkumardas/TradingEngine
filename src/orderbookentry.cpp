/**
 * @file orderbookentry.cpp
 * @author Debojit Kumar Das
 * @brief This file defines orderbook entry class
 * @version 0.1
 * @date 2023-11-25
 *
 * @copyright Copyright (c) 2023
 */

#include "orderbookentry.hpp"
#include <iostream>

OrderBookEntry::OrderBookEntry(double price, double amount, std::string timestamp, std::string product, OrderBookType order_type)
    : m_price(price), m_amount(amount), m_timestamp(std::move(timestamp)), m_product(std::move(product)), m_order_type(order_type) { }

OrderBookType OrderBookEntry::StringToOBT(std::string s) {
    if (s == "ask") {
        return OrderBookType::ASK;
    }
    if (s == "bid") {
        return OrderBookType::BID;
    }

    return OrderBookType::NONE;
}

OrderBookType OrderBookEntry::CheckOrderType(OrderBookEntry obe) {
    if (obe.m_order_type == OrderBookType::ASK)
        return OrderBookType::ASK;
    if (obe.m_order_type == OrderBookType::BID)
        return OrderBookType::BID;

    return OrderBookType::NONE;
}

void OrderBookEntry::GetValue() const {
    std::cout << "price: " << m_price << ";\t";
    std::cout << "amount: " << m_amount << ";\t";
    std::cout << "timestamp: " << m_timestamp << ";\t";
    std::cout << "product: " << m_product << '\n';
}
