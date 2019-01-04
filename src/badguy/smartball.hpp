//  SuperTux - Smart Snowball
//  Copyright (C) 2008 Wolfgang Becker <uafr@gmx.de>
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef HEADER_SUPERTUX_BADGUY_SMARTBALL_HPP
#define HEADER_SUPERTUX_BADGUY_SMARTBALL_HPP

#include "badguy/walking_badguy.hpp"

/** Easy to kill badguy that does not jump down from it's ledge. */
class SmartBall final : public WalkingBadguy
{
public:
  SmartBall(const ReaderMapping& reader);

  virtual std::string get_water_sprite() const override { return "images/objects/water_drop/pink_drop.sprite"; }

  virtual std::string get_class() const override { return "smartball"; }
  virtual std::string get_display_name() const override { return _("Smart Ball"); }

protected:
  virtual bool collision_squished(GameObject& object) override;

private:
  SmartBall(const SmartBall&) = delete;
  SmartBall& operator=(const SmartBall&) = delete;
};

#endif

/* EOF */
