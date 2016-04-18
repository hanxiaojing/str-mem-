char* strcpy(char* dst,const char* src)
{
	assert(src);
	char* ret = dst;
	while (*src)
	{
		*dst = *src;
		src++;
		dst++;
	}
	*dst = '\0';
	return ret;
}

char* strncpy(char* dst, const char* src, int count)
{
	assert(dst);
	assert(src);
	char* ret = dst;
	while (count--)
	{
		*dst = *src;
		dst++;
		src++;
	}
	*dst = '\0';
	return ret;
}

char* strcat(char* dst, char* src)
{
	assert(dst);
	assert(src);
	char* ret = src;
	while (*src)
	{
		src++;
	}
	while (*dst)
	{
		*src = *dst;
		dst++;
		src++;
	}
	*dst = '\0';
	return ret;
}


int strcmp(const char* dst, const char* src)
{
	assert(dst);
	assert(src);
	while (*src&&*dst)
	{
		if (*src == *dst)
		{
			src++;
			dst++;
		}
		else
		{
			return *src - *dst - '\0';
		}
	}
	return *src - *dst - '\0';
}


int strncmp(const char* dst, const char* src,size_t count)
{
	assert(dst);
	assert(src);
	while (count--&&*src&&*dst)
	{
		if (*src == *dst)
		{
			src++;
			dst++;
		}
		else
		{
			return *src - *dst - '\0';
		}
	}
	return *src - *dst - '\0';
}

char* strstr(const char* dst, const char* src)
{
	assert(dst);
	assert(src);
	char* s1 = dst;

	char* p = src;
	char* s2 = p;

	while (*s2)
	{
		s1 = dst;
		s2 = p;
		while (*s2 && *s1)
		{
			if (*s2 == *s1)
			{
				s1++;
				s2++;
			}
			else
			{
				p++; 
				break;
			}
		}
		if (*s1 == '\0')
		{
			return p;
		}
	}
	return NULL;
}

void* memcpy(void* dst, const void* src, size_t count)
{
	assert(dst);
	assert(src);
	char* dst_ = (char*)dst;
	char* src_ = (char*)src;
	while (count--)
	{
		*dst_++ = *src_++;
	}
	//即使此时count不为0，但是当我们将原数拷贝到新的数据结束，那也要结束程序。
	*dst_ = '\0';//必须加上结束标志，否则会乱码
	return dst;
}

void memmove(void* dst, const void* src, size_t count)
{
	assert(dst);
	assert(src);
	char* dst_ = (char*)dst;
	char* src_ = (char*)src;
	if (dst_ > src_&&dst < dst_ + count)
	{
		while (count--)
		{
			*(dst_+count) = *(src_+count);
			dst_++;
			src_++;
		}
	}
	else
	{
		while (count--)
		{
			*dst_ = *src_;
			dst_++;
			src_++;
		}
	}
	*dst_ = '\0';
	return dst;
}
