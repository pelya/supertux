//  SuperTux
//  Copyright (C) 2016 Ingo Ruhnke <grumbel@gmail.com>
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

#include "video/sdl_surface.hpp"

#include <sstream>
#include <stdexcept>

#include <SDL_image.h>

#include "physfs/physfs_sdl.hpp"

SDLSurfacePtr
SDLSurface::create_rgba(int width, int height)
{
#if SDL_BYTEORDER == SDL_BIG_ENDIAN
  Uint32 rmask = 0xff000000;
  Uint32 gmask = 0x00ff0000;
  Uint32 bmask = 0x0000ff00;
  Uint32 amask = 0x000000ff;
#else
  Uint32 rmask = 0x000000ff;
  Uint32 gmask = 0x0000ff00;
  Uint32 bmask = 0x00ff0000;
  Uint32 amask = 0xff000000;
#endif
  SDLSurfacePtr surface(SDL_CreateRGBSurface(0, width, height, 32, rmask, gmask, bmask, amask));
  if (!surface) {
    std::ostringstream out;
    out << "failed to create SDL_Surface: " << SDL_GetError();
    throw std::runtime_error(out.str());
  }

  return surface;
}

SDLSurfacePtr
SDLSurface::create_rgb(int width, int height)
{
#if SDL_BYTEORDER == SDL_BIG_ENDIAN
  Uint32 rmask = 0xff000000;
  Uint32 gmask = 0x00ff0000;
  Uint32 bmask = 0x0000ff00;
  Uint32 amask = 0x00000000;
#else
  Uint32 rmask = 0x000000ff;
  Uint32 gmask = 0x0000ff00;
  Uint32 bmask = 0x00ff0000;
  Uint32 amask = 0x00000000;
#endif
  SDLSurfacePtr surface(SDL_CreateRGBSurface(0, width, height, 24, rmask, gmask, bmask, amask));
  if (!surface) {
   std::ostringstream out;
    out << "failed to create SDL_Surface: " << SDL_GetError();
    throw std::runtime_error(out.str());
  }

  return surface;
}

SDLSurfacePtr
SDLSurface::from_file(const std::string& filename)
{
  SDLSurfacePtr surface(IMG_Load_RW(get_physfs_SDLRWops(filename.c_str()), 1));
  if (!surface)
  {
    std::ostringstream msg;
    msg << "Couldn't load image '" << filename << "' :" << SDL_GetError();
    throw std::runtime_error(msg.str());
  }
  else
  {
    return surface;
  }
}

/* EOF */
