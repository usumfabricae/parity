/****************************************************************\
*                                                                *
* Copyright (C) 2007 by Markus Duft <markus.duft@salomon.at>     *
*                                                                *
* This file is part of parity.                                   *
*                                                                *
* parity is free software: you can redistribute it and/or modify *
* it under the terms of the GNU Lesser General Public License as *
* published by the Free Software Foundation, either version 3 of *
* the License, or (at your option) any later version.            *
*                                                                *
* parity is distributed in the hope that it will be useful,      *
* but WITHOUT ANY WARRANTY; without even the implied warranty of *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  *
* GNU Lesser General Public License for more details.            *
*                                                                *
* You should have received a copy of the GNU Lesser General      *
* Public License along with parity. If not,                      *
* see <http://www.gnu.org/licenses/>.                            *
*                                                                *
\****************************************************************/

#ifndef __SYMBOLTABLEGENERATOR_H__
#define __SYMBOLTABLEGENERATOR_H__

#include <CoffArchive.h>
#include <CoffFileHeader.h>
#include <CoffImport.h>
#include <CoffSymbol.h>

#include <map>
#include <vector>
#include <string>

namespace parity
{
	namespace tasks
	{
		class MsSymbolTableGenerator {
		public:
			MsSymbolTableGenerator(binary::Symbol::SymbolVector& syms);
			void doWork();
		private:
			const binary::Symbol::SymbolVector& symbols_;
		};
	}
}

#endif
