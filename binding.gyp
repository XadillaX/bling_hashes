{
  "targets": [
    {
      "target_name": "bling",
      "sources": [
        "./src/byvoid_algorithms.cxx",
        "./src/bling.cxx"
      ],
      "include_dirs": [
        "<!(node -e \"require('nan')\")"
      ]
    }
  ]
}
