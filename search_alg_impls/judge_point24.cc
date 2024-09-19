#include<cstdio>
#include<vector>

#include "../search_algs.h"

double search::calculate(double a , double b, char type) {
    double result = 0;
    switch (type)
    {
    case '+':
        result = a + b;
        break;
    case '-':
        result = a - b;
        break;
    case '*':
        result = a * b;
        break;
    case '/':
        if (b <1e-10 && b > -1e-10) result = -1;
        else result = a /b;
        break;
    default:
        result = -1;
        break;
    }
    return result;
}

bool search::judgePoint24(std::vector<int>& nums) {
    char op_types[4] = {'+', '-', '*', '/'};
    
    for (int i1=0; i1<4; i1++) {
        for (int i2=0; i2<4; i2++) {
            if (i1 == i2) continue;
            for(int i3=0; i3<4; i3++) {
                if (i3==i1||i3==i2) continue;
                int i4 = 6 -i1 -i2 -i3;

                for (int oi1=0; oi1<4; oi1++) {
                    for (int oi2 = 0; oi2<4; oi2++) {
                        for (int oi3=0; oi3<4; oi3++) {
                            double result = 0;
                            double result2 = 0;
                            // (i1 +i2) + (i3 +i4)
                            result = calculate(nums[i1], nums[i2], op_types[oi1]);
                            result2 = calculate(nums[i3], nums[i4], op_types[oi2]);
                            result = calculate(result, result2, op_types[oi3]);
                            if (result - 24 >-1e-10 && result -24 < 1e-10) return true;
                            // ((i1+i2) + i3) + i4
                            result = calculate(nums[i1], nums[i2], op_types[oi1]);
                            result2 = calculate(result, nums[i3], op_types[oi2]);
                            result = calculate(result2, nums[i4], op_types[oi3]);
                            if (result - 24 >-1e-10 && result -24 < 1e-10) return true;
                            // (i1 + (i2 +i3)) + i4
                            result = calculate(nums[i2], nums[i3], op_types[oi1]);
                            result2 = calculate(nums[i1], result, op_types[oi2]);
                            result = calculate(result2, nums[i4], op_types[oi3]);
                            if (result - 24 >-1e-10 && result -24 < 1e-10) return true;
                            // i1 + ((i2 + i3) + i4)
                            result = calculate(nums[i2], nums[i3], op_types[oi1]);
                            result2 = calculate(result, nums[i4], op_types[oi2]);
                            result = calculate(nums[i1], result2, op_types[oi3]);
                            if (result - 24 >-1e-10 && result -24 < 1e-10) return true;
                            // i1 + (i2 + (i3 +i4))
                            result = calculate(nums[i3], nums[i4], op_types[oi1]);
                            result2 = calculate(nums[i2], result, op_types[oi2]);
                            result = calculate(nums[i1], result2, op_types[oi3]);
                            if (result - 24 >-1e-10 && result -24 < 1e-10) return true;
                        }
                    }
                }

            }
        }
    }
    return false;
}

bool search::judgePoint24_v2(std::vector<double>& nums, char* op_types) {
    if (nums.size() == 1) {
        if (nums[0] - 24 > -1e-10 && nums[0] - 24 < 1e-10) return true;
        return false;
    }

    for (int i=0; i< nums.size()-1; i++) {
        for (int j=i+1; j<nums.size(); j++) {
            std::vector<double> tmp;
            for(int k=0; k<nums.size(); k++) {
                if (k != i && k!=j) tmp.push_back(nums[k]);
            }
            for (int op_idx = 0; op_idx < 4; op_idx++) {
                tmp.push_back(calculate(nums[i], nums[j], op_types[op_idx]));
                bool flag = judgePoint24_v2(tmp, op_types);
                if (flag){
                    return true;
                }
                tmp.pop_back();
                if (op_types[op_idx] == '/' || op_types[op_idx] == '-') {
                    tmp.push_back(calculate(nums[j], nums[i], op_types[op_idx]));
                    if (judgePoint24_v2(tmp, op_types)) return true;
                    tmp.pop_back();
                }
            }
        }
    }
    return false; 
}

double search::calculate_v2(double a, double b, int type) {
    double result = 0;
    switch (type)
    {
    case 0:{
        result = a + b;
        break;
    }
    case 1: {
        result = a - b;
        break;
    }
    case 2: {
        result = a * b;
        break;
    }
    case 3: {
        if (b >-1e-6 && b <1e-6) {
            result = -1;
        }
        result = a / b;
        break;
    }
    default:
        break;
    }
    return result;
}

bool search::judgePoint24_v3(std::vector<double>& nums, char* op_types, std::string& res) {
    if(nums.size() == 1) {
        if ((nums[0]-24)>-1e-6 && (nums[0]-24)<1e-6) return true;
        return false;
    }
    int size = nums.size();
    for (int i=0; i<size-1; i++) {
        for (int j=i+1; j<size; j++) {
            std::vector<double> remains;
            for (int k=0; k<size; k++) {
                if (k!=i && k!=j) {
                    remains.push_back(nums[k]);
                }
            }
            for (int op_id = 0; op_id <4; op_id++) {
                // double val = calculate_v2(nums[i],nums[j], op_id);
                // remains.push_back(val);
                // bool flag = judgePoint24_v3(remains, op_types, res);
                // if (flag){
                //     return true;
                // }
                // remains.pop_back(); 
                // if (op_id == 1 || op_id == 3) {
                //     remains.push_back(calculate_v2(nums[j],nums[i], op_id));
                //     if (judgePoint24_v3(remains, op_types, res)) return true;
                //     remains.pop_back();
                // }
                double val = calculate_v2(nums[i], nums[j], op_id);
                remains.insert(remains.begin(), val);
                std::string new_res = res + ' ' + std::to_string(nums[i]) + \
                                      op_types[op_id] + std::to_string(nums[j]);
                bool isOk = judgePoint24_v3(remains, op_types, new_res);
                if (isOk) {
                    res = new_res;
                    return true;
                }
                remains.erase(remains.begin());
                if (op_id == 1 || op_id == 3) {
                    // remains.clear();
                    val = calculate_v2(nums[j], nums[i], op_id);
                    remains.insert(remains.begin(), val);
                    std::string new_res = res + ' ' + std::to_string(nums[j]) + \
                                        op_types[op_id] + std::to_string(nums[i]);
                    bool isOk = judgePoint24_v3(remains, op_types, new_res);
                    if (isOk) {
                        res = new_res;
                        return true;
                    }
                    remains.erase(remains.begin());
                }
            }
        }
    }
    return false;
}

