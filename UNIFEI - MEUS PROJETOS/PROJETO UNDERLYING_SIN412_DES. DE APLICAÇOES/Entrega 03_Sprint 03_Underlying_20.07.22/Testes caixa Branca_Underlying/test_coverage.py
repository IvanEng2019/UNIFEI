import sys
from .testenv.resources import dynamodb_strategies
from .testenv.aws import aws_credentials, lambda_context, dynamodb_resource
from ..app.app import lambda_handler, UpdateInterface
from .input_coverage import CoverageInput

def test_lambda_handler_read_strategyCN1(aws_credentials, dynamodb_strategies, dynamodb_resource, lambda_context):
    event = CoverageInput.input_read_strategyCN1()
    res = lambda_handler(event, lambda_context)
    print(res)
    assert res["statusCode"] == 200

def test_lambda_handler_read_strategyCN2(aws_credentials, dynamodb_strategies, dynamodb_resource, lambda_context):
    event = CoverageInput.input_read_strategyCN2()
    res = lambda_handler(event, lambda_context)
    print(res)
    assert res["statusCode"] == 500

def test_lambda_handler_read_sharedCN3(aws_credentials, dynamodb_strategies, dynamodb_resource, lambda_context):
    event = CoverageInput.input_read_sharedCN3()
    res = lambda_handler(event, lambda_context)
    print(res)
    assert res["statusCode"] == 200

def test_lambda_handler_read_strategyCA1(aws_credentials, dynamodb_strategies, dynamodb_resource, lambda_context):
    event = CoverageInput.input_read_strategyCA1()
    res = lambda_handler(event, lambda_context)
    print(res)
    assert res["statusCode"] == 200

def test_lambda_handler_read_strategyCA2(aws_credentials, dynamodb_strategies, dynamodb_resource, lambda_context):
    event = CoverageInput.input_read_strategyCA2()
    res = lambda_handler(event, lambda_context)
    print(res)
    assert res["statusCode"] == 500

def test_lambda_handler_read_sharedCA3(aws_credentials, dynamodb_strategies, dynamodb_resource, lambda_context):
    event = CoverageInput.input_read_sharedCA3()
    res = lambda_handler(event, lambda_context)
    print(res)
    assert res["statusCode"] == 200

def test_lambda_handler_read_strategyCC1(aws_credentials, dynamodb_strategies, dynamodb_resource, lambda_context):
    event = CoverageInput.input_read_strategyCC1()
    res = lambda_handler(event, lambda_context)
    print(res)
    assert res["statusCode"] == 200

def test_lambda_handler_read_strategyCCC3(aws_credentials, dynamodb_strategies, dynamodb_resource, lambda_context):
    event = CoverageInput.input_read_strategyCC3()
    res = lambda_handler(event, lambda_context)
    print(res)
    assert res["statusCode"] == 500

def test_lambda_handler_read_sharedCC5(aws_credentials, dynamodb_strategies, dynamodb_resource, lambda_context):
    event = CoverageInput.input_read_sharedCC5()
    res = lambda_handler(event, lambda_context)
    print(res)
    assert res["statusCode"] == 200

#def test_lambda_handler__get_bodyy(aws_credentials, dynamodb_strategies, dynamodb_resource, lambda_context):
 #   event = UpdateInterface.__get_body()
 #   res = lambda_handler(event, lambda_context)
  #  print(res)
   # assert res["statusCode"] == 200

#def test_lambda_handler__get_method(aws_credentials, dynamodb_strategies, dynamodb_resource, lambda_context):
 #   event = UpdateInterface.__get_method()
   # res = lambda_handler(event, lambda_context)
   # print(res)
   # assert res["statusCode"] == 200