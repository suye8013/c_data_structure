#include<stdlib.h>
#include<stdio.h>
#include"test.h"
int status = NULLSTATUS;

void do_null_status(FILE *ifp, FILE *ofp)
{
	int ch = fgetc(ifp);
	switch (ch)
	{
	case '/':
	{
				int ch1 = fgetc(ifp);
				switch (ch1)
				{
				case '/':
					fputc('/', ofp);
					fputc('/', ofp);
					status = CPPSTATUS;
					break;
				case '*':
					fputc('/', ofp);
					fputc('/', ofp);
					status = CSTATUS;
					break;
				case EOF:
					status = EOFSTATUS;
					break;
				default:
					fputc(ch, ofp);
					ungetc(ch1, ifp);
					status = NULLSTATUS;
					break;
				}
	}
		break;	
	case '\n':
			status = NULLSTATUS;
			break;
	case EOF:
		status = EOFSTATUS;
		break;
	default:
		fputc(ch, ofp);
		status = NULLSTATUS;
		break;
	}
}

void do_c_status(FILE *ifp, FILE *ofp)
{
	int ch = fgetc(ifp);
	switch (ch)
	{
		case '\n':
		fputc('/', ofp);
		fputc('/', ofp);
		status = CSTATUS;
		break;
	case '*':
	{
				int ch1 = fgetc(ifp);
				switch (ch1)
				{
				case '/':
					status = NULLSTATUS;
					break;
				case EOF:
					status = EOFSTATUS;
					break;
				default:
					fputc(ch, ofp);
					ungetc(ch, ifp);
					status = CSTATUS;
					break;
				}
	}
		break;
	case EOF:
		status = EOFSTATUS;
		break;
	default:
		fputc(ch, ofp);
		status = CSTATUS;
		break;
	}
}

void do_cpp_status(FILE *ifp, FILE *ofp)
{
	int ch = fgetc(ifp);
	switch (ch)
	{
	case '\n':
		fputc(ch, ofp);
		status = NULLSTATUS;
		break;
	case EOF:
		status = EOFSTATUS;
		break;
	default:
		fputc(ch, ofp);
		status =CPPSTATUS;
		break;
	}
}
static void work(FILE *ifp, FILE *ofp)
{
	while (status != EOFSTATUS)
	{
		switch (status)
		{
		case NULLSTATUS:
			do_null_status(ifp, ofp);
			break;
		case CSTATUS:
			do_c_status(ifp, ofp);
			break;
		case CPPSTATUS:
			do_cpp_status(ifp, ofp);
			break;
		case EOFSTATUS:
			break;
		default:
			break;
		}

	}
}

void test()
{
	FILE *ifp = fopen(INPUTFILE, "rb");
	FILE *ofp = fopen(OUTPUTFILE, "w");

	if (ifp == NULL || ofp == NULL)
	{
		fprintf(stderr, "this is fopen err\n");
		return;
	}

	work(ifp, ofp);

	fclose(ifp);
	fclose(ofp);
}
