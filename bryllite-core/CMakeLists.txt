file( GLOB sources "*.cpp" "*.hpp" )

add_executable( bryllite-core ${sources} )
target_link_libraries( bryllite-core bryllite-utils ${Boost_LIBRARIES} )
