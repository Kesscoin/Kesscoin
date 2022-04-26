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

#include <Block.hpp>
#include <sha.hpp>

Block::Block(Block* prev) {
    if (prev != NULL)
        this->block_num = prev->get_blocknum();

    this->submitted = false;
    this->right = NULL;
    prev != NULL ? this->left = prev : this->left = NULL;
    this->n_transactions = 0;

    if (prev == NULL) {
        this->block_num = 0;
        this->hash = "";
            
        for (int i = 0; i < 64; ++i) {
            this->hash += "0";
        }
    } else { 
        this->update_hash();
    }
}


void Block::update_hash() {
    std::string header_bin = "";
    header_bin += std::to_string(this->block_num);
    header_bin += std::to_string(this->n_transactions);
    header_bin += std::to_string(this->submitted);

    for (std::vector<Transaction>::iterator i = this->transactions.begin(); i != this->transactions.end(); ++i) {
        header_bin += i->get_from_id();
        header_bin += i->get_to_id();
        header_bin += i->get_hash();
        header_bin += std::to_string(i->get_amount());
        header_bin += std::to_string(i->get_timestamp());
    }

    picosha2::hash256_hex_string(header_bin, this->hash);      // Generate hash.
}


void Block::push_transaction(Transaction transaction) {
    this->transactions.push_back(transaction);
    this->n_transactions++;
    this->update_hash();
}


std::string Block::get_hash() {
    return this->hash;
}


size_t Block::get_n_transactions() {
    return this->n_transactions;
}


bool Block::is_submitted() {
    return this->submitted;
}


const Block* Block::get_prev() {
    return this->left;
}


Transaction Block::operator[](unsigned int n) {
    return this->transactions[n];
}


size_t Block::get_blocknum() {
    return this->block_num;
}
