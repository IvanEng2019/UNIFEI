import sys
from awsglue.transforms import *
from awsglue.utils import getResolvedOptions
from pyspark.context import SparkContext
from awsglue.context import GlueContext
from awsglue.job import Job
import pyspark.sql.functions as F
import pyspark.sql.types as T


args = getResolvedOptions(sys.argv, ["JOB_NAME"])
sc = SparkContext.getOrCreate()
glueContext = GlueContext(sc)
spark = glueContext.spark_session
job = Job(glueContext)
job.init(args["JOB_NAME"], args)


SOURCE_BUCKET = "ira-raw-data-market/b3/prices"
STOCKS_DESTINATION_BUCKET = "ira-datalake-stock-price"
OPTIONS_DESTINATION_BUCKET = "ira-datalake-option-price"


prices_schema = T.StructType([
        T.StructField("register_type", T.StringType(), True),
        T.StructField("date", T.StringType(), True),
        T.StructField("name", T.StringType(), True),
        T.StructField("company", T.StringType(), True),
        T.StructField("share_type", T.StringType(), True),
        T.StructField("forward_market_deadline", T.DoubleType(), True),
        T.StructField("currency", T.StringType(), True),
        T.StructField("open_price", T.DoubleType(), True),
        T.StructField("max_price", T.DoubleType(), True),
        T.StructField("min_price", T.DoubleType(), True),
        T.StructField("average_price", T.DoubleType(), True),
        T.StructField("close_price", T.DoubleType(), True),
        T.StructField("best_buy_price", T.DoubleType(), True),
        T.StructField("best_sell_price", T.DoubleType(), True),
        T.StructField("transactions", T.DoubleType(), True),
        T.StructField("quantity", T.DoubleType(), True),
        T.StructField("volume", T.DoubleType(), True),
        T.StructField("exercise_price", T.DoubleType(), True),
        T.StructField("price_correction_indicator", T.DoubleType(), True),
        T.StructField("expiration_date", T.StringType(), True),
        T.StructField("price_factor", T.DoubleType(), True),
        T.StructField("exercise_price_points", T.DoubleType(), True),
        T.StructField("isin_code", T.StringType(), True),
        T.StructField("distribution_share_number", T.DoubleType(), True),
        T.StructField("type", T.StringType(), True),
        T.StructField("folder", T.StringType(), True)
])


df = spark.read.format("csv") \
            .options(delimiter=",", header=True) \
            .schema(prices_schema) \
            .load(f"s3a://{SOURCE_BUCKET}/") \
            .dropDuplicates()


stock_columns = [
        "date",
        "name",
        "company",
        "share_type",
        "open_price",
        "max_price",
        "min_price",
        "average_price",
        "close_price",
        "best_buy_price",
        "best_sell_price",
        "transactions",
        "quantity",
        "volume",
        "price_factor",
        "isin_code",
]

option_columns = [
        "exercise_price",
        "expiration_date",
        "type",
] + stock_columns

stocks = df.filter(F.col("folder") == "acoes").orderBy(F.col("date")).select(stock_columns)

options = df.filter(F.col("folder") == "opcoes").orderBy(F.col("date")).select(option_columns)

spark.conf.set("spark.sql.sources.partitionOverwriteMode", "dynamic")

stocks.write \
    .partitionBy("isin_code") \
    .format("parquet") \
    .mode("overwrite") \
    .save(f"s3a://{STOCKS_DESTINATION_BUCKET}/")


options.write \
    .partitionBy("isin_code") \
    .format("parquet") \
    .mode("overwrite") \
    .save(f"s3a://{OPTIONS_DESTINATION_BUCKET}/")