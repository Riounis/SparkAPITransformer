spark.read.textFile("helloworld.txt").map(line => 1).select(reduceAggregator((a: Int, b: Int) => a + b)).collect()(0)
