{
  'targets': [
    {
      'target_name': 'elephant',
      'sources': ['src/node_elephant.cc', 'src/wrapped_elephant.cc', 'inc/elephant.cc', 'inc/MH3/MurmurHash3.cc'],
      'cflags': ['-fexceptions'],
      'cflags_cc': ['-fexceptions'],
      'cflags!': ['-fno-exceptions'],
      'cflags_cc!': ['-fno-exception'],
      'conditions': [
        ['OS=="win"', {
            'msvs_settings': {
              'VCCLCompilerTool': {
                'AdditionalOptions': [ '/EHsc' ]
              }
            }
          }
        ],
        ['OS=="mac"', {
            'xcode_settings': {
              'GCC_ENABLE_CPP_EXCEPTIONS': 'YES'
            }
          }
        ]
      ]
    }
  ]
}
