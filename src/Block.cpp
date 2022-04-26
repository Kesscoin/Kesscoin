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

Block::Block(Block* prev) {
    this->block_num = 0;
    this->submitted = 0;
    this->right = NULL;
    prev != NULL ? this->left = prev : this->left = NULL;
}


void Block::push_transaction(Transaction transaction) {
    this->transactions.push_back(transaction);
    this->n_transactions++;
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


const Block* Block::operator[](unsigned int n) {
    if (this->right == NULL) return NULL;
    const Block* cur = this->right;    // Current block.

    if (cur->block_num == n) return cur;   // Return if it is what we requested.

    // Traverse the tree to get the requested block.
    while (cur !=  NULL) {
        if (cur->block_num == n) return cur;
        cur = cur->right;
    }

    return NULL;    // We did not find the request block.
}
