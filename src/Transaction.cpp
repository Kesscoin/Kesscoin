/*
    MIT License
 
    Copyright (c) 2022 Ian Moffett
    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:
    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.
    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.
*/


#include <Transaction.hpp>
#include <sha.hpp>


Transaction::Transaction(std::string from_id, std::string to_id, AMOUNT amount) {
    this->from_id = from_id;
    this->to_id = to_id;
    this->amount = amount;

    std::string header_bin;

    // Add up everything to header_bin.
    for (int i = 0; i < this->from_id.size(); ++i) {
        header_bin += this->from_id[i];
    }

    for (int i = 0; i < this->to_id.size(); ++i) {
        header_bin += this->to_id[i];
    }

    header_bin += std::to_string(static_cast<int>(this->amount));
    picosha2::hash256_hex_string(header_bin, this->hash);
}


std::string Transaction::get_hash() {
    return this->hash;
}

std::string Transaction::get_from_id() {
    return this->from_id;
}


std::string Transaction::get_to_id() {
    return this->to_id;
}


char* Transaction::get_timestamp() {
    return ctime(&this->timestamp);
}


AMOUNT Transaction::get_amount() {
    return this->amount;
}
