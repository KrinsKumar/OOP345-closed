// Workshop 9 - Multi-Threading, Thread Class
// process_data.cpp
// 2021/1/5 - Jeevan Pant
/*
    Name - Krinskumar Bhaveshkumar Vaghasia
    Seneca ID - 169722212
    Seneca email - kvaghasia@myseneca.ca
    Date of Completion - 1 April, 2023
*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include "process_data.h"

using namespace std;
using namespace placeholders;

namespace sdds_ws9 {

	void computeAvgFactor(const int* arr, int size, int divisor, double& avg) {
		avg = 0;
		for (int i = 0; i < size; i++) {
			avg += arr[i];
            //std::this_thread::sleep_for(std::chrono::nanoseconds(50));
		}
		avg /= divisor;
	}

	void computeVarFactor(const int* arr, int size, int divisor, double avg, double& var) {
		var = 0;
		for (int i = 0; i < size; i++) {
			var += (arr[i] - avg) * (arr[i] - avg);
            //std::this_thread::sleep_for(std::chrono::nanoseconds(50));
		}
		var /= divisor;
	}
	ProcessData::operator bool() const {
		return total_items > 0 && data && num_threads>0 && averages && variances && p_indices;
	}

	ProcessData::ProcessData(std::string filename, int n_threads) {  
		// TODO: Open the file whose name was received as parameter and read the content
		//         into variables "total_items" and "data". Don't forget to allocate
		//         memory for "data".
		//       The file is binary and has the format described in the specs.
        ifstream file(filename, ios::in | ios::binary);
        if (file) {
            file.read(reinterpret_cast<char*>(&total_items), 4);

            data = new int[total_items];
            for (auto i = 0; i < total_items; ++i) {
                file.read(reinterpret_cast<char*>(&data[i]), 4);
            }
        }

		std::cout << "Item's count in file '"<< filename << "': " << total_items << std::endl;
		std::cout << "  [" << data[0] << ", " << data[1] << ", " << data[2] << ", ... , "
		          << data[total_items - 3] << ", " << data[total_items - 2] << ", "
		          << data[total_items - 1] << "]\n";

		// Following statements initialize the variables added for multi-threaded 
		//   computation
		num_threads = n_threads; 
		averages = new double[num_threads] {};
		variances = new double[num_threads] {};
		p_indices = new int[num_threads+1] {};
		for (int i = 0; i < num_threads+1; i++)
			p_indices[i] = i * (total_items / num_threads);
	}
	ProcessData::~ProcessData() {
		delete[] data;
		delete[] averages;
		delete[] variances;
		delete[] p_indices;
	}

	// TODO Improve operator() function from part-1 for multi-threaded operation. Enhance the  
	//   function logic for the computation of average and variance by running the 
	//   function computeAvgFactor and computeVarFactor in multile threads. 
	// The function divides the data into a number of parts, where the number of parts is 
	//   equal to the number of threads. Use multi-threading to compute average-factor for 
	//   each part of the data by calling the function computeAvgFactor. Add the obtained 
	//   average-factors to compute total average. Use the resulting total average as the 
	//   average value argument for the function computeVarFactor, to compute variance-factors 
	//   for each part of the data. Use multi-threading to compute variance-factor for each 
	//   part of the data. Add computed variance-factors to obtain total variance.
	// Save the data into a file with filename held by the argument fname_target. 
	// Also, read the workshop instruction.

    int ProcessData::operator()(std::string filename, double& avg, double& variance) {

        std::vector<std::thread> threads;

        auto computeAVG = bind(computeAvgFactor, _1, _2, total_items, _3);
        auto computeVar = bind(computeVarFactor, _1, _2, total_items, _3, _4);

        for (auto i = 0; i < num_threads; ++i) {
            int size = p_indices[i + 1] - p_indices[i];
            threads.push_back(thread(computeAVG, &(data[p_indices[i]]), size, ref(averages[i])));
        }
        avg = 0;
        for (auto i = 0; i < num_threads; ++i) {
            threads[i].join();
            avg += averages[i];
        }

        threads.clear();
        for (auto i = 0; i < num_threads; ++i) {
            int size = p_indices[i + 1] - p_indices[i];
            threads.push_back(thread(computeVar, &(data[p_indices[i]]), size, avg, ref(variances[i])));
        }
        variance = 0;
        for (auto i = 0; i < num_threads; ++i) {
            threads[i].join();
            variance += variances[i];
        }

        ofstream file(filename, ios::out | ios::binary);
        const char* temp = reinterpret_cast<const char*>(&total_items);
        file.write(temp, 4);

        for (auto i = 0; i < total_items; ++i) {
            const char* temp = reinterpret_cast<const char*>(&data[i]);
            file.write(temp, 4);
        }
        return 1;

    }
    



}