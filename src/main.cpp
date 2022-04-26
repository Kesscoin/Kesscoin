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

#include <iostream>
#include <Block.hpp>
#include <Transaction.hpp>


int main() {
    Block genesis(NULL);
    Block blk1(&genesis);

    for (int i = 0; i < 55; ++i) {
        Transaction cur(std::to_string(i), std::to_string(i), 12.99);
        blk1.push_transaction(cur);
        std::cout << "BLK1 CURRENT HASH: " << blk1.get_hash() << "\n\n" << "CURRENT TRANSACTION HASH: " << cur.get_hash() << "\n\n";
    }
}
