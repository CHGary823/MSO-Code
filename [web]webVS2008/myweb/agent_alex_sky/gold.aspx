<%@ Page language="c#" Codebehind="gold.aspx.cs" AutoEventWireup="false" Inherits="web.agent.gold" %>
<%@ Register TagPrefix="uc1" TagName="agentmenu" Src="../control/agentmenu.ascx" %>
<%@ Register TagPrefix="uc1" TagName="agenttop" Src="../control/agenttop.ascx" %>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN" >
<HTML>
	<HEAD>
		<title>agentcp</title>
		<meta content="Microsoft Visual Studio .NET 7.1" name="GENERATOR">
		<meta content="C#" name="CODE_LANGUAGE">
		<meta content="JavaScript" name="vs_defaultClientScript">
		<meta content="http://schemas.microsoft.com/intellisense/ie5" name="vs_targetSchema">
		<SCRIPT language="JavaScript" src="Common/JavaScript/Menu.js"></SCRIPT>
		<LINK href="Common/CSS/Default.CSS" type="text/css" rel="stylesheet">
		<LINK href="Common/CSS/menuStyleXP.CSS" type="text/css" rel="stylesheet">
	</HEAD>
	<body MS_POSITIONING="GridLayout">
		<form id="Form1" method="post" runat="server">
			<uc1:agenttop id="agenttop1" runat="server"></uc1:agenttop>
			<table id="Table1" cellSpacing="1" cellPadding="3" width="780" border="0">
				<tr>
					<td vAlign="top" width="207" rowSpan="2">
						<table cellSpacing="0" cellPadding="0" width="100%" align="center" border="0">
							<tr bgColor="#bcbcbc">
								<td>
									<table cellSpacing="1" cellPadding="10" width="100%" border="0">
										<tr bgColor="#efefef">
											<td vAlign="top" height="498"><uc1:agentmenu id="agentmenu1" runat="server"></uc1:agentmenu></td>
										</tr>
										<tr bgColor="#f9f9f9">
											<td height="80">
												<div align="center">
													<p><font color="#ff6633"><b><font color="#ff6666"></font></b>
															<asp:Button id="btnlogout" runat="server" Text="�˳���̨"></asp:Button></font></p>
												</div>
											</td>
										</tr>
									</table>
								</td>
							</tr>
						</table>
					</td>
					<td vAlign="top" width="556">
						<table id="Table2" cellSpacing="0" cellPadding="0" width="563" align="center" border="0">
							<tr bgColor="#bcbcbc">
								<td>
									<table id="Table3" cellSpacing="1" cellPadding="8" width="100%" border="0">
										<tr bgColor="#efefef">
											<td vAlign="top" align="left" height="350">
												<TABLE id="Table4" cellSpacing="1" cellPadding="1" width="456" border="0" style="WIDTH: 456px; HEIGHT: 104px">
													<TBODY>
														<TR>
															<TD style="WIDTH: 55px; HEIGHT: 3px" align="left"><B>���Űl��</B></TD>
															<TD align="left" style="HEIGHT: 3px"><FONT face="�����w"></FONT></TD>
														</TR>
														<TR>
															<TD style="WIDTH: 77px; HEIGHT: 5px" align="left">��Ҏ�̖</TD>
															<TD style="HEIGHT: 5px" align="left">
																<asp:textbox id="tbuserid" runat="server" Columns="10" Width="120px"></asp:textbox>*Ո�c����м��ˌ��Ƿ����_</TD>
														</TR>
														<TR>
															<TD style="WIDTH: 77px; HEIGHT: 6px" align="left">���Ŕ���</TD>
															<TD align="left" style="HEIGHT: 6px"><asp:textbox id="tbgold" runat="server" Width="120px" Columns="10"></asp:textbox>*��������ؓ�������������</TD>
														</TR>
														<TR>
															<TD align="left" colSpan="2" style="HEIGHT: 2px">ע��:�l��������᲻Ҫˢ�����,Ո�cһ�����I,��t�����}�l��(����c��"�l�ͽ���"�ܾÛ]����,����ȿ������I�_�Jһ��,��Ҫ�B�m�c��)</TD>
														</TR>
														<TR>
															<TD align="center" colSpan="2"><asp:button id="btnedit" runat="server" Text="�l�ͽ���"></asp:button></TD>
														</TR>
													</TBODY>
												</TABLE>
												</FONT>
											</td>
										</tr>
									</table>
								</td>
							</tr>
						</table>
					</td>
				</tr>
			</table>
		</form>
	</body>
</HTML>
