Event::Event() {

}

bool Event::operator==(const Event & rightSide) const{
	if(rightSide.time == time) {
		return true;
	}else{
		return false;
	}
}

bool Event::operator!=(const Event & rightSide) const{
	if(rightSide.time == time) {
		return false;
	}else{
		return true;
	}
}

bool Event::operator>(const Event & rightSide) const{
	if(rightSide.time < time) {
		return false;
	}else{
		return true;
	}
}

bool Event::operator<(const Event & rightSide) const{
	if(rightSide.time > time) {
		return false;
	}else{
		return true;
	}
}

bool Event::operator=(const Event & rightSide) {
	arrival = rightSide.arrival;
	time = rightSide.time;
	length = rightSide.length;
	
	return true;
}
