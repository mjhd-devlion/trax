#include "ArrayBoard.h"

#include <cstring>
#include <iostream>

ArrayBoard::ArrayBoard() {
    this->_left   = 256;
    this->_top    = 256;
    this->_right  = 256;
    this->_bottom = 256;

    std::memset(this->_board, 0, sizeof(Cell) * 512 * 512);
}

Cell& ArrayBoard::operator()(Cord x, Cord y) {

#ifndef _NO_VALIDATIONS_
    if ((x >= this->Width()) ||
        (y >= this->Height()))
        throw "Out of Range";
#endif

    auto& cell = this->_board[this->_left + x][this->_top + y];

    std::cout << "X:" << (int)x << std::endl;
    std::cout << "Y:" << (int)y << std::endl;

    std::cout << this->_left << "," << this->_right << std::endl;
    std::cout << this->_top << "," << this->_bottom << std::endl;

    if (this->_right  == this->_left + x) this->_right++;
    if (this->_bottom == this->_top  + y) this->_bottom++;
    if (x == 0) this->_left--;
    if (y == 0) this->_top--;

    std::cout << "------------" << std::endl;

    std::cout << this->_left << "," << this->_right << std::endl;
    std::cout << this->_top << "," << this->_bottom << std::endl;

    return cell;
}

const Cell& ArrayBoard::Get(Cord x, Cord y) const {
#ifndef _NO_VALIDATIONS_
    if ((x >= this->Width()) ||
        (y >= this->Height()))
        return EmptyCell;
#endif

    return this->_board[this->_left + x][this->_top + y];
}

Cord ArrayBoard::Width() const {
    return this->_right - this->_left + 1;
}

Cord ArrayBoard::Height() const {
    return this->_bottom - this->_top + 1;
}
