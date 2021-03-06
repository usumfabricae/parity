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

#ifndef __STATISTICS_H__
#define __STATISTICS_H__

#include <Path.h>

#include <vector>
#include <map>
#include <string>

namespace parity
{
	namespace statistics
	{
		typedef void (*StatisticHandler)(std::string const& key, std::string const& value, std::string const& type);
		typedef void (*StatisticPrinter)();

		typedef struct {
			std::string key;
			StatisticHandler handler;
		} StatisticHandlerMapping;

		typedef std::map<std::string, StatisticPrinter> StatisticPrinterVector;
		typedef std::vector<StatisticHandlerMapping> StatisticMappingVector;

		extern StatisticPrinterVector available_stats;
		extern StatisticMappingVector available_mappings;

		extern bool short_;

		void DefaultHandler(std::string const& key, std::string const& value, std::string const& type);
		void ProcessFile(const utils::Path& path);
	}
}

#endif

