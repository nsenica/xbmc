/*
*      Copyright (C) 2017 Team Kodi
*      https://kodi.tv
*
*  This Program is free software; you can redistribute it and/or modify
*  it under the terms of the GNU General Public License as published by
*  the Free Software Foundation; either version 2, or (at your option)
*  any later version.
*
*  This Program is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
*  GNU General Public License for more details.
*
*  You should have received a copy of the GNU General Public License
*  along with XBMC; see the file COPYING.  If not, see
*  <http://www.gnu.org/licenses/>.
*
*/

#ifndef ODBUNIQUEID_H
#define ODBUNIQUEID_H

#include <odb/core.hxx>
#include <odb/lazy-ptr.hxx>

#include <string>

PRAGMA_DB (model version(1, 1, open))

PRAGMA_DB (object pointer(std::shared_ptr) \
                  table("uniqueid"))
class CODBUniqueID
{
public:
  CODBUniqueID()
  {
    m_value = "";
    m_type = "";
    m_synced = false;
  };
  
PRAGMA_DB (id auto)
  unsigned long m_idUniqueID;
PRAGMA_DB (type("VARCHAR(255)"))
  std::string m_value;
PRAGMA_DB (type("VARCHAR(255)"))
  std::string m_type;
  
  //Members not stored in the db, used for sync ...
PRAGMA_DB (transient)
  bool m_synced;
  
private:
  friend class odb::access;
  
PRAGMA_DB (index member(m_type))
PRAGMA_DB (index member(m_value))
};

#endif /* ODBUNIQUEID_H */