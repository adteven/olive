# Olive - Non-Linear Video Editor
# Copyright (C) 2019 Olive Team
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

add_subdirectory(backend)
add_subdirectory(ocioconf)

set(OLIVE_SOURCES
  ${OLIVE_SOURCES}
  render/audioparams.h
  render/audioparams.cpp
  render/audioplaybackcache.h
  render/audioplaybackcache.cpp
  render/color.h
  render/color.cpp
  render/colormanager.h
  render/colormanager.cpp
  render/colorprocessor.h
  render/colorprocessor.cpp
  render/diskmanager.h
  render/diskmanager.cpp
  render/framehashcache.h
  render/framehashcache.cpp
  render/managedcolor.h
  render/managedcolor.cpp
  render/pixelformat.h
  render/pixelformat.cpp
  render/playbackcache.h
  render/playbackcache.cpp
  render/rendermodes.h
  render/videoparams.h
  render/videoparams.cpp
  PARENT_SCOPE
)

set(OLIVE_RESOURCES
  ${OLIVE_RESOURCES}
  PARENT_SCOPE
)
