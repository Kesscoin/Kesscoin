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

#ifndef BLOCK_HPP
#define BLOCK_HPP

#include <string>
#include <vector>


struct Transaction {
    std::string sender_id;
    std::string reciever_id;
    std::string amt;
    time_t timestamp;
    std::string hash;
};


class Block {
    private:
        std::vector<Transaction> transactions;
        std::string hash;
        size_t block_num;
        size_t n_transactions;
        bool submitted;
        Block* right;
        Block* left;
    public:
        Block(Block* prev);
        void push_transaction(Transaction transaction);
        std::string get_hash();
        size_t get_n_transactions();
        bool is_submitted();
        size_t get_height();
        const Block* operator[](unsigned int n);
        const Block* get_prev();
};

#endif
