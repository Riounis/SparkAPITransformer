spark.read.textFile("helloworld.txt").map(line => 1:Long).select(reduceAggregator((a: Long, b: Long) => a + b)).collect()(0)
