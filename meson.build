project('pocket-racing-server', 'cpp',
    version : '0.1.0',
    meson_version : '>=0.55.0',
    default_options : ['cpp_std=c++17', 'buildtype=debugoptimized']
)

asio = dependency('asio')
websockets = dependency('websocketpp')

src = files('src/bin/server.cpp')

executable('pocket-racing-server',
    src,
    dependencies: [asio, websockets]
)
