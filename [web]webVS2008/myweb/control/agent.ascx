<%@ Control Language="c#" AutoEventWireup="false" Codebehind="agent.ascx.cs" Inherits="web.control.agent" TargetSchema="http://schemas.microsoft.com/intellisense/ie5"%>
<TABLE id="Table1" cellSpacing="0" cellPadding="0" width="96%" border="0">
	<TR>
		<TD height="30" style="WIDTH: 94px"></TD>
		<TD align="center" height="30"><SPAN id="AscxNewsView1_L_Title" style="FONT-WEIGHT: bold"><%=nation%>�����M��ʽ</SPAN></TD>
	</TR>
	<TR>
		<TD style="WIDTH: 94px; HEIGHT: 10px"><FONT face="����">������</FONT></TD>
		<TD style="BACKGROUND-POSITION: 50% bottom; BACKGROUND-ATTACHMENT: scroll; BACKGROUND-REPEAT: no-repeat; HEIGHT: 10px"
			vAlign="top" height="10">
			<b>
				<%=name%>
			</b>
		</TD>
	</TR>
	<TR>
		<TD style="WIDTH: 94px; HEIGHT: 19px"><FONT face="����">�֙C��</FONT></TD>
		<TD style="BACKGROUND-POSITION: 50% bottom; BACKGROUND-ATTACHMENT: scroll; BACKGROUND-REPEAT: no-repeat; HEIGHT: 19px"
			vAlign="top" height="19"><%=hp%></TD>
	</TR>
	<TR>
		<TD style="WIDTH: 94px; HEIGHT: 19px"><FONT face="����">�̶��Ԓ��</FONT></TD>
		<TD style="BACKGROUND-POSITION: 50% bottom; BACKGROUND-ATTACHMENT: scroll; BACKGROUND-REPEAT: no-repeat; HEIGHT: 19px"
			vAlign="top" height="19"><%=tp%><FONT face="����"></FONT></TD>
	</TR>
	<TR>
		<TD style="WIDTH: 94px; HEIGHT: 19px">MSN��</TD>
		<TD style="BACKGROUND-POSITION: 50% bottom; BACKGROUND-ATTACHMENT: scroll; BACKGROUND-REPEAT: no-repeat; HEIGHT: 19px"
			vAlign="top" height="19"><%=msn%></TD>
	</TR>
	<TR>
		<TD style="WIDTH: 94px; HEIGHT: 19px">QQ��</TD>
		<TD style="BACKGROUND-POSITION: 50% bottom; BACKGROUND-ATTACHMENT: scroll; BACKGROUND-REPEAT: no-repeat; HEIGHT: 19px"
			vAlign="top" height="19"><%=qq%></TD>
	</TR>
	<TR>
		<TD style="WIDTH: 94px; HEIGHT: 120px">�y�Ў�����</TD>
		<TD style="BACKGROUND-POSITION: 50% bottom; BACKGROUND-ATTACHMENT: scroll; BACKGROUND-REPEAT: no-repeat; HEIGHT: 120px"
			vAlign="top" height="120">
			<asp:TextBox id="TextBox1" runat="server" TextMode="MultiLine" Width="320px" Height="112px" ReadOnly="True"></asp:TextBox></TD>
	</TR>
	<TR>
		<TD style="WIDTH: 94px; HEIGHT: 76px">������</TD>
		<TD style="BACKGROUND-POSITION: 50% bottom; BACKGROUND-ATTACHMENT: scroll; BACKGROUND-REPEAT: no-repeat; HEIGHT: 76px"
			vAlign="top" height="76">
			<asp:TextBox id="TextBox2" runat="server" TextMode="MultiLine" Width="320px" Height="112px" ReadOnly="True"></asp:TextBox></TD>
	</TR>
	<TR>
		<TD style="WIDTH: 94px; HEIGHT: 19px"><FONT face="����">�����ţ�</FONT></TD>
		<TD style="BACKGROUND-POSITION: 50% bottom; BACKGROUND-ATTACHMENT: scroll; BACKGROUND-REPEAT: no-repeat; HEIGHT: 19px"
			vAlign="top" height="19"><font color="#ff3333"><b>����</b></font></TD>
	</TR>
</TABLE>
