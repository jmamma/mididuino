#ifndef MNM_DATA_ENCODER_H__
#define MNM_DATA_ENCODER_H__

#include "DataEncoder.hh"

class MNMDataToSysexEncoder : public DataEncoder {
  uint16_t retLen;
  uint16_t cnt7;

  uint8_t lastByte;
  uint8_t lastCnt;
  bool isFirstByte;
  
public:
  MNMDataToSysexEncoder(uint8_t *_sysex = NULL, uint16_t _sysexLen = 0) {
    init(_sysex, _sysexLen);
  }

  virtual void init(uint8_t *_sysex, uint16_t _sysexLen);
  DATA_ENCODER_RETURN_TYPE encode7Bit(uint8_t inb);
  virtual DATA_ENCODER_RETURN_TYPE pack8(uint8_t inb);
  DATA_ENCODER_RETURN_TYPE packLastByte();
  virtual uint16_t finish();
};

class MNMSysexToDataEncoder : public DataEncoder {
public:
  uint16_t retLen;
  uint8_t cnt7;
  uint8_t repeat;
  uint16_t cnt;
  uint8_t bits;
  uint8_t tmpData[7];
  
  MNMSysexToDataEncoder(uint8_t *_data = NULL, uint16_t _maxLen = 0) {
    init(_data, _maxLen);
  }

  virtual void init(uint8_t *_data, uint16_t _maxLen);
  virtual DATA_ENCODER_RETURN_TYPE pack8(uint8_t inb);
  DATA_ENCODER_RETURN_TYPE unpack8Bit();
  virtual uint16_t finish();
};

class MNMSysexDecoder : public DataDecoder {
  uint8_t cnt7;
  uint8_t bits;
  uint8_t tmpData[7];
	uint16_t cnt;
	uint8_t repeatCount;
	uint8_t repeatByte;
	
public:
	MNMSysexDecoder(uint8_t *_data = NULL, uint16_t _maxLen = 0) {
		init(_data, _maxLen);
	}
	
	virtual void init(uint8_t *_data, uint16_t _maxLen);
	virtual DATA_ENCODER_RETURN_TYPE get8(uint8_t *c);
	virtual DATA_ENCODER_RETURN_TYPE getNextByte(uint8_t *c);
};

#endif /* MNM_DATA_ENCODER_H__ */
