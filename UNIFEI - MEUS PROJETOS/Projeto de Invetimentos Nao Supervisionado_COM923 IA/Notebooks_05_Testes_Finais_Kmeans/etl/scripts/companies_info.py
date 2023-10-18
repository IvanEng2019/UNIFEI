import sys
from awsglue.transforms import *
from awsglue.utils import getResolvedOptions
from pyspark.context import SparkContext
from awsglue.context import GlueContext
from awsglue.job import Job
import pyspark.sql.functions as F
import pyspark.sql.types as T


args = {"JOB_NAME": "test"}
sc = SparkContext.getOrCreate()
glueContext = GlueContext(sc)
spark = glueContext.spark_session
job = Job(glueContext)
job.init(args["JOB_NAME"], args)

B3_SOURCE_BUCKET = "ira-raw-data-market/b3/traded-companies-info"
CVM_SOURCE_BUCKET = "ira-raw-data-market/cvm/traded-companies-info"


b3_schema = T.StructType([
        T.StructField("issuingCompany", T.StringType(), True),
        T.StructField("companyName", T.StringType(), True),
        T.StructField("tradingName", T.StringType(), True),
        T.StructField("cnpj", T.StringType(), True),
        T.StructField("industryClassification", T.StringType(), True),
        T.StructField("industryClassificationEng", T.StringType(), True),
        T.StructField("activity", T.StringType(), True),
        T.StructField("website", T.StringType(), True),
        T.StructField("hasQuotation", T.BooleanType(), True),
        T.StructField("marketIndicator", T.IntegerType(), True),
        T.StructField("market", T.StringType(), True),
        T.StructField("institutionCommon", T.StringType(), True),
        T.StructField("institutionPreferred", T.StringType(), True),
        T.StructField("code", T.StringType(), True),
        T.StructField("codeCVM", T.StringType(), True),
        T.StructField("lastDate", T.StringType(), True),
        T.StructField("otherCodes", T.ArrayType([
            T.StructType([
                T.StructField("code", T.StringType(), True),
                T.StructField("isin", T.StringType(), True)
            ])
        ]), True),
        T.StructField("hasEmissions", T.BooleanType(), True),
        T.StructField("hasBDR", T.BooleanType(), True),
        T.StructField("typeBDR", T.StringType(), True),
        T.StructField("describleCategoryBVMF", T.StringType(), True),
])

def set_code(codes):
    return codes["code"]

def set_isin(codes):
    return codes["isin"]


code_set = F.udf(set_code, T.StringType())
isin_set = F.udf(set_isin, T.StringType())


b3 = spark.read.format("csv") \
            .options(delimiter=",", header=True) \
            .schema(b3_schema) \
            .load(f"s3a://{B3_SOURCE_BUCKET}/") \
            .dropDuplicates()

# b3 = b3.filter(F.col("otherCodes").isNotNull()) \
#             .withColumn("codes", F.explode(b3.otherCodes)) \
#             .withColumnRenamed("code", "mainCode") \
#             .withColumn("code", code_set("codes")) \
#             .withColumn("isin_code", isin_set("codes"))


cvm = spark.read.format("csv") \
            .options(delimiter=",", header=True, encoding="ISO-8859-1") \
            .load(f"s3a://{CVM_SOURCE_BUCKET}/") \
            .dropDuplicates() \
            .withColumnRenamed("CD_CVM", "codeCVM")