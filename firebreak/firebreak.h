#pragma once
#ifndef vectori
#include <vector>
#define vectori
#endif
namespace firebreak {
	typedef std::vector<bool*> vbool;
	typedef size_t BIT;
	/**
	  * The Firebreak bool Class
	  *
	  * Main Class of Firebreak, holds pointer to your bool variables
	  *
	  */
	class firebreakBool {
	private:
		vbool boolv;
	public:
		firebreakBool();
		/**
	      * Add a bool Poiner
	      *
	      * You need to create the bools self
	      *
	      * @param booltoadd Pointer to the bool to add
	      */
		void addBool(bool* booltoadd);
		/**
		  * Get Alloc Buffer
		  *
		  * Generates the minimum size of the buffer needed to write a valid buffer
		  * 
		  * @return The size of the buffer to alloc
		  */
		size_t getBufferSize();
		/**
		  * Write to buffer
		  *
		  * Writes to an existing buffer the generated bytes of the bool values
		  *
		  * @param buffer A Pointer to the buffer to write to
		  * @param maxsize The size of the buffer
		  */
		void writeToBuffer(char* buffer, size_t maxsize);
		/**
		  * Read from buffer
		  *
		  * Reads from buffer and override the bool's with the readed values
		  *
		  * @param buffer A Pointer to the buffer to read from
		  * @param buffersize The size of the buffer
		  */
		void readFromBuffer(char* buffer, size_t buffersize);
	};
}
