#!/usr/bin/env python3

def apply(config, args):
    config['baseimg'] = 'baserom.z64'
    config['myimg'] = 'pokemonsnap.z64'
    config['mapfile'] = 'build/pokemonsnap.map'
    config['source_directories'] = ['.']
