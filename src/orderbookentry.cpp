/**
 * @file orderbookentry.cpp
 * @author Debojit Kumar Das
 * @brief This file implements the interface for orderbook entry class
 * @version 0.1
 * @date 2023-11-25
 *
 * @copyright Copyright (c) 2023
 */

#include "orderbookentry.hpp"
#include <iostream>

OrderBookEntry::OrderBookEntry(double price, double amount, std::string timestamp, std::string product, OrderType order_type)
    : m_price(price), m_amount(amount), m_timestamp(std::move(timestamp)), m_product(std::move(product)), m_order_type(order_type) { }

OrderType OrderBookEntry::StringToOBT(std::string s) {
    if (s == "ask") {
        return OrderType::ASK;
    }
    if (s == "bid") {
        return OrderType::BID;
    }

    return OrderType::NONE;
}

OrderType OrderBookEntry::CheckOrderType(OrderBookEntry obe) {
    if (obe.m_order_type == OrderType::ASK)
        return OrderType::ASK;
    if (obe.m_order_type == OrderType::BID)
        return OrderType::BID;

    return OrderType::NONE;
}

std::string OrderBookEntry::GetProduct() {
    return m_product;
}

OrderType OrderBookEntry::GetOrderType() {
    return m_order_type;
}

std::string OrderBookEntry::GetTimeStamp() {
    return m_timestamp;
}

double OrderBookEntry::GetPrice() {
    return m_price;
}

void OrderBookEntry::GetValue() const {
    std::cout << "price: " << m_price << ";\t";
    std::cout << "amount: " << m_amount << ";\t";
    std::cout << "timestamp: " << m_timestamp << ";\t";
    std::cout << "product: " << m_product << '\n';
}
