//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** Listing 7-6.
    @file NotFoundException.cpp */

NotFoundException::NotFoundException(const std::string& message)
                       : std::logic_error("Not Found Exception: " + message)
{
}  // end constructor
