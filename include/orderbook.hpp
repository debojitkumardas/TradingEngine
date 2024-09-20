#ifndef ORDERBOOK_H
#define ORDERBOOK_H

#include "orderbookentry.hpp"
#include <string>
#include <vector>

class OrderBook {
public:
    /** construct reading a csv file */
    OrderBook(std::string& filename);
    /** return vector of all known products (eg: USD, ETH, etc.) */
    std::vector<std::string> GetKnownProducts();
    /** return vector of orders according to the sent filters */
    std::vector<OrderBookEntry> GetOrders(OrderType type, std::string product, std::string timestamp);

    /** returns the earliest time in the orderbook */
    std::string GetEarliestTime();
    /** returns the next time
     * after the sent time in the orderbook
     * if there is no next timestamp,
     * wraps around to the start
     **/
    std::string GetNextTime(std::string& timestamp);

    static double GetHighPrice(std::vector<OrderBookEntry>& orders);
    static double GetLowPrice(std::vector<OrderBookEntry>& orders);

private:
    std::vector<OrderBookEntry> m_orders;
};

#endif // !ORDERBOOK_H
