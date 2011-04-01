#ifndef OSMIUM_OSMIUM_HPP
#define OSMIUM_OSMIUM_HPP

#ifdef WITH_GEOS
# include <geos/geom/GeometryFactory.h>
#endif

#ifdef WITH_JAVASCRIPT
# include <v8.h>
# include <unicode/ustring.h>
# include <osmium/utils/unicode.hpp>
#endif // WITH_JAVASCRIPT

namespace Osmium {

    struct global {
        bool debug;
#ifdef WITH_GEOS
        geos::geom::GeometryFactory *geos_geometry_factory;
#endif
    };

    extern struct global global;

} // namespace Osmium

#ifdef OSMIUM_MAIN
struct Osmium::global Osmium::global;
#endif

// check way geometry before making a shplib object from it
// normally this should be defined, otherwise you will generate invalid linestring geometries
#define CHECK_WAY_GEOMETRY

#include <osmium/osm.hpp>
#include <osmium/input.hpp>
#include <osmium/framework.hpp>

#ifdef WITH_JAVASCRIPT
# include <JavascriptTemplate.hpp>
# include <JavascriptOutputCSV.hpp>
# include <JavascriptOutputShapefile.hpp>
# include <HandlerJavascript.hpp>
#endif // WITH_JAVASCRIPT

#endif // OSMIUM_OSMIUM_HPP
