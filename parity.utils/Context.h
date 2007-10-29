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

#ifndef __CONTEXT_H__
#define __CONTEXT_H__

#include <string>
#include <cstdlib>
#include <map>
#include <vector>

#include "Path.h"
#include "Exception.h"
#include "Color.h"

#include "ContextGen.h"

namespace parity
{
	namespace utils
	{
		class Context;

		typedef struct {
			std::string name;
			void (Context::*setter)(const std::string&);
		} ContextMap;

		class Context : public ContextGen {
		public:
			Context();
			virtual ~Context();

			static Context& getContext();

			const ContextMap* getMapping(const std::string&) const;

			//
			// Explicit setters and getters. Those may also override
			// generated setters and getters,
			//
			void setDebugLevel(const std::string& ref);
			void setDefaultOutput(const Path& ref);
			void setDefaultOutputString(const std::string& val) { setDefaultOutput(Path(val)); }
			void setObjectsLibrariesString(const std::string& val);

			//
			// Dumps all the values currently set in the Context
			//
			void dump(bool intern);

			//
			// FIXME: this is public, since the BinaryGatherer needs to lookup
			// each files implicit dependencies.
			//
			bool isBadLinkerPath(const Path &pth);
			bool isBadCompilerPath(const Path& pth);
			Path lookupLibrary(const std::string& name, bool isMinusL);

		private:
			//
			// cannot copy!
			//
			Context(const Context& rhs) {}

			void cleanup();

			static const ContextMap mapping_[];
		};
	}
}

#endif
