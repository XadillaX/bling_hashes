{
  "targets": [
    {
      "target_name": "bling",
      "sources": [
        "./src/byvoid/algorithms.cxx",
        "./src/cityhash/cityhash.cxx",
        "./src/bling.cxx"
      ],
      "include_dirs": [
        "<!(node -e \"require('nan')\")"
      ]
    }
  ]
}
