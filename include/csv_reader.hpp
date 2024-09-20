/**
 * @file csv_reader.cpp
 * @author Debojit Kumar Das
 * @brief This file defines the interface to read and tokenise a CSV file and create orderbook entry objets using those tokens.
 * @version 0.1
 * @date 2023-11-25
 *
 * @copyright Copyright (c) 2023
 */

#ifndef CSV_READER_H
#define CSV_READER_H

#include "orderbookentry.hpp"
#include <string>
#include <vector>

class CSVReader {
public:
    CSVReader();
    static std::vector<OrderBookEntry> ReadCSV(std::string& csv_file_path);

private:
    static std::vector<std::string> Tokenise(std::string, char, char esc_seq = ' ');
    static OrderBookEntry StringsToOBEObj(std::vector<std::string> tokens);
};

#endif // !CSV_READER_H
