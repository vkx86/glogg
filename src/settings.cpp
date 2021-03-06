/*
 * Copyright (C) 2018-2019 Sergei Dyshel and other contributors
 *
 * This file is part of glogg.
 *
 * glogg is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * glogg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with glogg.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "settings.h"

#define PREAMBLE "Setting" << (group() + "." + key)

Settings::Settings() : QSettings("glogg", "glogg") {

}

QString Settings::getString(const QString &key, const QString &default_)
{
    if (contains(key)) {
        auto val = value(key);
        if (val.type() != QVariant::String) {
            ERROR << PREAMBLE << "is not a string";
            return default_;
        }
        return val.toString();
    } else {
        WARN << PREAMBLE << " is missing";
        return default_;
    }
}