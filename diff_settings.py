#!/usr/bin/env python3

def apply(config, args):
    config['baseimg'] = 'baserom.z64'
    config['myimg'] = 'build/pokemonsnap.z64'
    config['mapfile'] = 'build/pokemonsnap.map'
    config['source_directories'] = ['.']
    config['makeflags'] = ['COMPARE=0']
