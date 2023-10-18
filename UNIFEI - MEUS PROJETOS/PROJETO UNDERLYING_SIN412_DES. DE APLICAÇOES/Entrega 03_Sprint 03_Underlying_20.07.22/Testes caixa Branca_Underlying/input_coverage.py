import json
from copy import deepcopy

base_api_request = {
    "rawPath": "/v1/",
    "body": "{}"
}

class CoverageInput:

    @staticmethod
    def input_read_strategyCN1():
        case = deepcopy(base_api_request)
        case["rawPath"] += "strategy"
        case["body"] = json.dumps({"id":"18199ad0-47fb-4592-8fb2-008726efab95"})
        return case

    @staticmethod
    def input_read_strategyCN2():
        case = deepcopy(base_api_request)
        case["rawPath"] += "strategy"
        case["body"] = json.dumps({"id":"1234"})
        return case

    @staticmethod
    def input_read_sharedCN3():
        case = deepcopy(base_api_request)
        case["rawPath"] += "shared"
        case["body"] = json.dumps({})
        return case

    @staticmethod
    def input_read_strategyCA1():
        case = deepcopy(base_api_request)
        case["rawPath"] += "strategy"
        case["body"] = json.dumps({"id":"18199ad0-47fb-4592-8fb2-008726efab95"})
        return case

    @staticmethod
    def input_read_strategyCA2():
        case = deepcopy(base_api_request)
        case["rawPath"] += "strategy"
        case["body"] = json.dumps({"id":"%4esFD12"})
        return case

    @staticmethod
    def input_read_sharedCA3():
        case = deepcopy(base_api_request)
        case["rawPath"] += "shared"
        case["body"] = json.dumps({})
        return case

    @staticmethod
    def input_read_strategyCC1():
        case = deepcopy(base_api_request)
        case["rawPath"] += "strategy"
        case["body"] = json.dumps({"id":"18199ad0-47fb-4592-8fb2-008726efab95"})
        return case

    @staticmethod
    def input_read_strategyCC3():
        case = deepcopy(base_api_request)
        case["rawPath"] += "strategy"
        case["body"] = json.dumps({"id":"hrtrd122-456"})
        return case

    @staticmethod
    def input_read_sharedCC5():
        case = deepcopy(base_api_request)
        case["rawPath"] += "shared"
        case["body"] = json.dumps({})
        return case