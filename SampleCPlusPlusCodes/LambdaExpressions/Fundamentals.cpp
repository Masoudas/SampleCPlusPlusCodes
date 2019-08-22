	
void firstLambda() {
	// We define a lambda expression for the slidebar argument of createTrackbar. For definition of lambda, 
	// see https://docs.microsoft.com/en-us/cpp/cpp/lambda-expressions-in-cpp?view=vs-2019 .
	// Note that the first bracket indicates how we want to access the outside variables. 
	// For example, [=] means access by value, [&] means access by reference, we may even pass "this" in classes. [*this] means capute this by value!
	auto lambda = [&](int pos, void*) -> void {
		

		g_cap.set(cv::CAP_PROP_POS_FRAMES, pos);	// Using the ampersand, we have access by reference.
		if (!g_dontset)	g_run = 1;
		g_dontset = 0;
	};

	// Here's how we call this lambda  
	void* ptr; 	
	lambda(5, ptr);

	// When the lambda is generated, it looks something like this:
	//struct lambda {
	//		void operator()(int i, void*) const { body }
	//};
	// The point is that the lambda is not actually a function, it is a type, hence for example it cannot be directly passed 
	// when a pointer to function is needed.

}